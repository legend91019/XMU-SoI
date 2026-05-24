import os
import re

def parse_filename(filename, root):
    # Ignore specific paths
    if '.git' in root or '大一下教材' in root:
        return None
    
    name, ext = os.path.splitext(filename)
    
    # Needs to match some keywords to be an exam or related file
    keywords = ['期中', '期末', '模拟', '试卷', '试题', '答案', '卷', '题', '解答', '复习']
    if not any(k in name for k in keywords):
        # Also check if the path itself is indicative, like inside "期中" directory
        if not any(k in root for k in keywords):
            return None
        
    year = "未知年份"
    # Find year (2010 to 2030)
    year_match = re.search(r'(20[12]\d)', name)
    if not year_match:
        year_match = re.search(r'(20[12]\d)', root)
    if year_match:
        year = year_match.group(1)
    else:
        # Match "17级", "19201"
        m = re.search(r'(1[0-9])级', name) or re.search(r'(1[0-9])级', root)
        if m:
            year = "20" + m.group(1)
        else:
            m = re.search(r'([12][0-9])[12]01', name)
            if m:
                year = "20" + m.group(1)
            
    exam_type = "未知类别"
    if "期中" in name or "期中" in root:
        exam_type = "期中"
    elif "期末" in name or "期末" in root:
        exam_type = "期末"
        
    sub_type = "其他"
    if any(k in name for k in ["答案", "解答", "key"]):
        sub_type = "答案"
    elif any(k in name for k in ["模拟", "复习"]):
        sub_type = "复习模拟"
    elif any(k in name for k in ["试卷", "试题", "卷", "题", "A", "B", "QA"]):
        sub_type = "试题"
        
    # Only rename if we figured out at least something
    if year == "未知年份" and exam_type == "未知类别":
        return None
        
    new_name = f"{year}-{exam_type}-{sub_type}{ext}"
    return new_name

def main():
    TARGET_DIR = r"d:\Desktop\课堂"
    os.chdir(TARGET_DIR)
    
    renames = []
    
    for root, dirs, files in os.walk('.'):
        # Prevent renaming files in .git
        if '.git' in root:
            continue
            
        used_names = set(f.lower() for f in files)
        
        for file in files:
            new_name = parse_filename(file, root)
            if not new_name:
                continue
            
            # Don't rename if already correct
            if new_name == file:
                continue
                
            # Handle duplicates
            base, ext = os.path.splitext(new_name)
            counter = 1
            final_name = new_name
            while final_name.lower() in used_names:
                final_name = f"{base}_{counter}{ext}"
                counter += 1
                
            used_names.add(final_name.lower())
            
            old_path = os.path.join(root, file)
            new_path = os.path.join(root, final_name)
            renames.append((old_path, new_path))
            
    for old_path, new_path in renames:
        print(f"Renaming: {old_path} -> {new_path}")
        os.rename(old_path, new_path)
        
    print(f"Total renamed: {len(renames)}")

if __name__ == '__main__':
    main()
