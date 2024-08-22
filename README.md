
# manWc
Manual Linux wc tool, for fun!

This project is a fun project written in C++ to manually create the `wc` tool in Linux.

If you don't know what the `wc` tool does, the `wc` (word count) tool in Linux is a command-line utility used to count the number of lines, words, and bytes (or characters) in files or standard input. It's a versatile tool that provides basic statistics about text files or input streams.

## To use this simple tool:

### Step 1: Clone the repository
First, clone the repository:
```bash
git clone https://github.com/Edwardobird/manWc.git
```

### Step 2: Compile the tool
Navigate to the cloned directory and compile the C++ source code (if you are not there already):
```bash
cd manWc
g++ -o manWc main.cpp
```

### Step 3: Run the tool
Use the following commands to count lines, characters, or words:
```bash
./manWc -l myfile.txt
./manWc -c myfile.txt
./manWc -w myfile.txt
```

### Optional: Add manWc to your PATH
To use `manWc` as a command from any directory, you can add it to your system's PATH.

#### Step 4: Move the executable to a directory in your PATH
Move the compiled executable to a directory that is already in your PATH, such as `/usr/local/bin`:
```bash
sudo mv manWc /usr/local/bin/
```

#### Step 5: Verify the PATH
Ensure that the directory (e.g., `/usr/local/bin`) is in your PATH by running:
```bash
echo $PATH
```

#### Step 6: Use manWc globally
Now you can use the `manWc` command from anywhere in your terminal:
```bash
manWc -l myfile.txt
```

### Optional: Customize the name
If you prefer, you can rename the command:
```bash
sudo mv /usr/local/bin/manWc /usr/local/bin/wc_custom
```

Then use it like this:
```bash
wc_custom -l myfile.txt
```

Enjoy using your custom `wc` tool!
