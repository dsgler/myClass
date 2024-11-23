import os

def list_files_without_extension(folder_path):
    files_to_delete = []
    # 遍历指定文件夹下的所有文件
    for filename in os.listdir(folder_path):
        # 获取文件的完整路径
        file_path = os.path.join(folder_path, filename)
        # 检查是否是文件且没有后缀名
        if os.path.isfile(file_path) and os.path.splitext(filename)[1]!=".c":
            files_to_delete.append(file_path)
    return files_to_delete

def delete_files(files):
    for file_path in files:
        os.remove(file_path)
        print(f"Deleted: {file_path}")

if __name__ == "__main__":
    folder_path = input("Enter the folder path: ")
    files_to_delete = list_files_without_extension(folder_path)
    
    if files_to_delete:
        print("The following files will be deleted:")
        for file_path in files_to_delete:
            print(file_path)
        
        confirm = input("Do you want to delete these files? (yes/no): ").lower()
        if confirm == 'yes':
            delete_files(files_to_delete)
            print("Files deleted.")
        else:
            print("Operation cancelled.")
    else:
        print("No files without extension found.")