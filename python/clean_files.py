import os

def main():
    """
    Walks and cleans (rename and deletes (yet to be implemented) some files)
    through all folders
    recursively from the current folder.
    """
    for subdir, dirs, files in os.walk("./4_misc"):
#        for file in files:
#            if (file.endswith("ABCDEF.py")):
#                break
#
#            path = os.path.join(subdir, file)
#            os.rename(path, path.lower())

            os.rename(subdir, subdir.lower())


if __name__ == "__main__":
    main()
