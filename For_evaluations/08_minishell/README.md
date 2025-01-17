<h1 align=center>Filter scripts for zstenger's 42_minishell_tester</h1>

# Setup
First you have to clone zstenger's 42_minishell_tester in the root of your minishell repository and follow his instructions. 

Then copy the scripts in the root of your minishell repository.

Give the scripts execution permisions: `chmod +x name_of_the_script`

In some of them, you have to modify the path to 42_minishell_tester.

Then follow their instructions. They are at the end of this page, or in the code of each script (open them in text editor).


# WHAT EACH SCRIPT DOES
*print_testfile_lines.sh* : FOR PRINTING THE TESTFILE CONTENTS


*print_result_n_testfile.sh* : FOR PRINTING THE TEST RESULTS AND THE TESTFILE CONTENTS OF ALL THE FAILS


*print_filtered_result.sh* : FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC)


*print_filtered_result_n_testfile.sh* : FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC) AND THE TESTFILE CONTENTS.


<h2 align=center>USEFUL COMMANDS</h2>

- Use this command to filter the test result to only show the failed tests:

`awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'`

E.G:

mstest m | awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'

(remember that mstest is an alias for executing the minishell tester)



***
- Use this command to look for the executed commands in the minishell tester script:

`cat /nfs/homes/marondon/42_minishell_tester/cmds/mand/1_variables.sh | head -55`

Ex if the failed line is this one:

  23:	STD_OUT: ❌  STD_ERR: ✅  EXIT_CODE: ✅  /nfs/homes/marondon/42_minishell_tester/cmds/mand/1_variables.sh:55 



***
- Use this method for telling minishell to execute a series of commands inside a txt file:

bash < tests_to_run.txt



***
- To see "special chars" (like end of line), add `| cat -e¸` to the command:

bash < tests_to_run.txt | cat -e



***
- To comment out some test inside the txt file (instead of delete them), use # and then execute this command:

`grep -v '^#' commands.txt | ./minishell`

# SCRIPTS INSTRUCTIONS
***
**print_testfile_lines.sh**: FOR PRINTING THE TESTFILE CONTENTS
1. Put this script in the root of your minishell folder.
2. Give it execution permission (`chmod +x print_testfile_lines.sh`).
3. Execute it (`./print_testfile_lines.sh`)

It needs the path+filename of the test, and a comma-separated list of the
lines (line head -line_number).
It's like typing `cat path_filename | head -line_number` but it's "automatic".
It prompts for the path+file and then it prompts for the line numbers
to execute the 'head' command.
It prints whole command file for that specific test; even if it's multiline.
E.g: Use it like this:
`./print_file_lines.sh`
Enter the file path:
/nfs/homes/marondon/42_minishell_tester/cmds/mand/1_scmds.sh
Enter the comma-separated list of line numbers:
19,24,48,52

***
**print_result_n_testfile.sh**: FOR PRINTING THE TEST RESULTS AND THE TESTFILE CONTENTS OF ALL THE FAILS
1. Put this script in the root of your minishell folder.
2. Give it execution permission (chmod +x print_result_n_testfile.sh).
3. Inside this script look for
"/nfs/homes/marondon/42_minishell_tester" and change
marondon with your username. (the script needs the full path to
42_minishell_tester/tester.sh)

It needs the test result output. Either you redirect the input from a saved
test result file, or you pipe it.
Note that for filtering the test, the folloing command should be used:
`awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'`
If you don't filter the test, or either you pipe it without filtering;
then it'll print the whole test, and will print only the test fie content
of the failing test.
E.g: Use it like this:
`./print_result_n_testfile.sh < test_result_file.txt`
Or
`mstest m | awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt' | ./print_result_n_testfile.sh`
Or
`mstest m | ./print_result_n_testfile.sh`
(this one shows whole test without filtering, but only prints file contents
of failed test).

***
**print_filtered_result.sh**: FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC)
1. Put this script in the root of your minishell folder.
2. Give it execution permission (`chmod +x print_filtered_result.sh`).
3. Inside this script look for
"/nfs/homes/marondon/42_minishell_tester" and change
marondon with your username. (the script needs the full path to
42_minishell_tester/tester.sh)
4. Execute it (`./print_filtered_result.sh`) and it'll automatically run
zstenger's minishell tester.

It ask for:
The test mode to use (m, vm, d, ne, b, etc) (read zstenger93 tester usage).
The failed "test part" to print (e.g: STD_OUT, STD_ERR, etc)
Then it runs the whole test, and only prints the fails on the selected parts;
but WITHOUT including the testfile contents.
So you'll only see in what you fail, but not the commands that were used
to test your minishell.

***
**print_filtered_result_n_testfile.sh**: FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC) AND THE TESTFILE CONTENTS.
1. Put this script in the root of your minishell folder.
2. Give it execution permission (`chmod +x print_filtered_result_n_testfile.sh`)
3. Inside this script look for
"/nfs/homes/marondon/42_minishell_tester" and change
marondon with your username. (the script needs the full path to
42_minishell_tester/tester.sh)
4. Execute it (`./print_filtered_result_n_testfile.sh`) and it'll automatically
run zstenger's minishell tester.

It's a combination of the 3 previous scripts (print_testfile_lines.sh,
print_result_n_testfile.sh, print_filtered_result.sh).
It ask for:
The test mode to use (m, vm, d, ne, b, etc) (read zstenger93 tester usage).
The failed "test part" to print (e.g: STD_OUT, STD_ERR, etc)
Then it runs the whole test, and prints the test result
and the tesfile contents only of the selected "test parts"
E.g: Use it like this:
```bash
./print_filtered_result_n_testfile.sh
Enter the test mode (m, vm, d, ne, b):
m
Include all tested parts? (STD_OUT, STD_ERR, EXIT_CODE, LEAKS) [y/n]:
n
Include STD_OUT? [y/n]:
y
Include STD_ERR? [y/n]:
y
Include EXIT_CODE? [y/n]:
y
Include LEAKS? [y/n]:
n
```
