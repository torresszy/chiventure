#define _XOPEN_SOURCE 500
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include <stdio.h>
#include <ftw.h>
#include <unistd.h>
#include "libobj/obj.h"
#include "libobj/load.h"
#include "load_internal.h"
#include "common/utlist.h"
#include "common/uthash.h"

#define TEST_OUT_PATH "test_files/"
#define TEST_DATA_PATH "../../../tests/libobj/test_files/"

// Creates the test output directory
void make_testdir()
{
    char cwd[10 * (MAXLEN_ID + 1)] = {0};
    strcat(cwd, TEST_OUT_PATH);
    printf("cwd: %s\n", cwd);
    int rc = mkdir(cwd, 0777);
    cr_assert_eq(rc, 0, "Could not make temporary output directory");
}

// Deletes a file
// From https://stackoverflow.com/questions/5467725/how-to-delete-a-directory-and-its-contents-in-posix-c
int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    int rv = remove(fpath);

    if (rv)
        perror(fpath);

    return rv;
}

// Performs rm -rf on a directory
// From https://stackoverflow.com/questions/5467725/how-to-delete-a-directory-and-its-contents-in-posix-c
int rmrf(char *path)
{
    return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}

// Deletes the test directory
void clean_testdir()
{
    // char path[10 * (MAXLEN_ID + 1)] = {0};
    // strcat(path, TEST_OUT_PATH);
    // int rc = rmrf(path);
    // cr_assert_eq(rc, 0, "Could not remove temporary output directory");
}

/* Tests _strip_expected_extension for an expected extension */
Test(test_load_wdz, extension_success)
{
    char str[] = "test_str.json";

    bool rc = _strip_expected_extension(str, "json");

    cr_assert_eq(rc, true, "_strip_expected_extension failed");
    cr_assert_str_eq(str, "test_str", 
        "_strip_expected_extension incorrectly modified the string");
}

/* Tests _strip_expected_extension for no extension */
Test(test_load_wdz, extension_none)
{
    char str[] = "test_str";

    bool rc = _strip_expected_extension(str, "json");

    cr_assert_eq(rc, false, "_strip_expected_extension failed");
}

/* Tests _strip_expected_extension for the wrong extension */
Test(test_load_wdz, extension_wrong)
{
    char str[] = "test_str.diff";

    bool rc = _strip_expected_extension(str, "json");

    cr_assert_eq(rc, false, "_strip_expected_extension failed");
}

/* Tests _strip_expected_extension for the wrong final extension */
Test(test_load_wdz, extension_wrong_nested)
{
    char str[] = "test_str.json.diff";

    bool rc = _strip_expected_extension(str, "json");

    cr_assert_eq(rc, false, "_strip_expected_extension failed");
}

/* Tests parsing a simple zip file */
Test(test_load_wdz, zip_simple, .init = make_testdir, .fini = clean_testdir)
{
    // TODO- make zip, turn to obj, check items in obj
    // https://gist.github.com/clalancette/bb5069a09c609e2d33c9858fcc6e170e
    // https://libzip.org/documentation/zip_open.html
    // https://libzip.org/documentation/zip_dir_add.html
    // zip_file_add

    char zip_name[10 * (MAXLEN_ID + 1)] = {0};
    strcat(zip_name, TEST_OUT_PATH);
    strcat(zip_name, "zip_simple.zip");

    // Create the zip
    int errorp;
    zip_t *zip = zip_open(zip_name, ZIP_CREATE | ZIP_EXCL, &errorp);
    cr_assert_not_null(zip, "Could not create zip file; code: %d", errorp);

    // Add GAME.json to the zip
    char *data_name = "GAME.json";
    char data_path[10 * (MAXLEN_ID + 1)] = {0};
    strcat(data_path, TEST_DATA_PATH);
    strcat(data_path, data_name);
    zip_source_t *zip_src = zip_source_file(data_path, data_name, 0, 0);
    int tmp = zip_file_add(zip, data_name, zip_src, ZIP_FL_ENC_UTF_8);
    printf("tmp: %d\n", tmp);

    // Write and save to disk
    int rc = zip_close(zip);
    printf("close: %d, e: %d\n", rc, zip_error_code_zip(zip_get_error(zip)));

    // Read the zip into an obj
    obj_t *obj = obj_new("test");
    load_obj_zip(obj, zip_name);

    dump_obj(obj);
}
