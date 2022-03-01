from pathlib import Path

def map_func(word: str) -> str:
    return word.strip().lower() + "\n"

def filter_func(word: str) -> bool:
    return len(word) > 2 and word[:-1].isalpha()

def main():
    with open("3-9-dictionary.txt", "w") as file:
        for dict_file_path in Path("Word lists in csv").iterdir():
            with open(dict_file_path) as dict_file:
                lines = dict_file.readlines()
                words = set(filter(filter_func, map(map_func, lines)))
                file.writelines(words)
            # Found stuff with unreadable characters
            # with open(dict_file_path, "rb") as dict_file:
            #     data = dict_file.read()
            #     x = data.find(0x96)
            #     if x != -1:
            #         print(f"{dict_file.name}: {x}: {data[x-15:x+15]}")

if __name__ == "__main__":
    main()
