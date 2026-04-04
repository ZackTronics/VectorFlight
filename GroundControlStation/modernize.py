import os
import re
import shutil

# CONFIGURATION
# Extensions to scan (cpp source and headers)
EXTENSIONS = ('.cpp', '.h', '.c', '.hpp')
# Markers to find
START_PI   = r"//BEGIN_SWAP_PI"
END_PI     = r"//END_SWAP_PI"
START_DESK = r"//BEGIN_SWAP_DESK"
END_DESK   = r"//END_SWAP_DESK"

def process_file(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    original_content = content

    # 1. Replace PI blocks
    # Pattern: Finds //BEGIN_SWAP_PI, captures everything in between, finds //END_SWAP_PI
    # Replacement: #ifdef TARGET_HARDWARE_PI [content] #endif
    pi_pattern = re.compile(re.escape(START_PI) + r"(.*?)" + re.escape(END_PI), re.DOTALL)
    content = pi_pattern.sub(r"#ifdef TARGET_HARDWARE_PI\1#endif", content)

    # 2. Replace DESK blocks
    # Pattern: Finds //BEGIN_SWAP_DESK, captures everything in between, finds //END_SWAP_DESK
    # Replacement: #else [content] #endif (Assuming Desk is the 'else' to Pi) 
    # OR better: #ifndef TARGET_HARDWARE_PI
    desk_pattern = re.compile(re.escape(START_DESK) + r"(.*?)" + re.escape(END_DESK), re.DOTALL)
    
    # Strategy: Use #ifndef TARGET_HARDWARE_PI so it defaults to Desktop if flag is missing
    content = desk_pattern.sub(r"#ifndef TARGET_HARDWARE_PI\1#endif", content)

    if content != original_content:
        print(f"Updating: {filepath}")
        # Create backup just in case
        shutil.copy(filepath, filepath + ".bak")
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)

def main():
    # Walk the current directory
    root_dir = os.getcwd()
    print(f"Scanning {root_dir} for legacy swap macros...")
    
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            if file.endswith(EXTENSIONS):
                process_file(os.path.join(root, file))
    
    print("Done! Backups created with .bak extension.")

if __name__ == "__main__":
    main()