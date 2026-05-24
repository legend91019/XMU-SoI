import os
import subprocess

LARGE_FILE_THRESHOLD = 50 * 1024 * 1024 # 50 MB
TARGET_DIR = r"d:\Desktop\课堂"

os.chdir(TARGET_DIR)

large_files = []
for root, _, files in os.walk('.'):
    if '.git' in root:
        continue
    for f in files:
        filepath = os.path.join(root, f)
        if os.path.getsize(filepath) > LARGE_FILE_THRESHOLD:
            # normalize path for git
            git_path = filepath.replace('\\', '/').lstrip('./')
            large_files.append(git_path)

if large_files:
    # 1. Add to .gitignore
    with open('.gitignore', 'a', encoding='utf-8') as f:
        f.write('\n# Large files\n')
        for file in large_files:
            f.write(f'{file}\n')
            
    # 2. git rm --cached
    for file in large_files:
        print(f"Untracking {file}...")
        subprocess.run(['git', 'rm', '--cached', file], capture_output=True)

print(f"Processed {len(large_files)} large files.")
