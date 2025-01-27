# This file contains the code that defines Player class
# Defines a Room class and its methods for conversion to WDL.
import json
from to_wdl.util import PROPERTY_ALIASES, ACTION_ALIASES
from warnings import warn
from collections import ChainMap
from to_wdl.wdl_item import Item

class Player_Class:
    def __init__(self, name: str, contents: dict, default: str):
        self.contents = contents
        self.name = name or "a class"
        self.default = default

        self.wdl_contents = {}

    def to_json(self) -> str: 
        """ For internal testing only: converts a game to its JSON format """
        return json.dumps(self.to_wdl_structure(),indent=2)
    
    def to_wdl_structure(self) -> dict:
        """
            Converts a Game to WDL structure using its properties. Generates 
            default values where they are missing.
        """
        for k, v in self.contents.items():
            if k in PROPERTY_ALIASES:
                self.wdl_contents[PROPERTY_ALIASES[k]] = v
            elif k == "attributes":
                self.wdl_contents["attributes"] = self.contents["attributes"]
            elif k == "base_stats":
                self.wdl_contents["base_stats"] = self.contents["base_stats"]
            else:
                self.wdl_contents[k] = v

        if self.default == "no-defaults":
            warn(f'''warning: no default values generated for {self.name}, wdl file may not run''')
        self.generate_defaults()
        return {self.name: self.wdl_contents}

    def generate_defaults(self):
        """
            Ensures that an Item can be converted to WDL by filling in 
            neccesary information (like short and long description) that is not 
            included with its default values.
        """
        
        # generate default for short description
        if 'short_desc' not in self.wdl_contents:
            default_name = self.name
            self.wdl_contents['short_desc'] = f"{default_name}"
            warn(f'''missing: short description for {default_name}, generated default: {self.wdl_contents['short desc']}''')

        # generate default for long description
        if 'long_desc' not in self.wdl_contents:
            short_desc = self.wdl_contents.get('short_desc', '')
            default = f"This is a {self.name}."
            self.wdl_contents['long_desc'] = f"{default}"
            warn(f'''missing: long description for {self.name}, generated default: {self.wdl_contents['long desc']}''')