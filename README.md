# Cellular Automaton written in C
A cellular automaton defined by 256 set of rules.

## Install
Clone a repository and build it with `make` program:

```bash
$ make ca
```

## Use
You can use without arguments:

```bash
$ ./ca
```

Result:

```bash
----------------------------
Rule:                    030
Binary rule:        00011110
Number of gens:          010
Number of cells:         028
----------------------------

              .
             ...
            ..  .
           .. ....
          ..  .   .
         .. .... ...
        ..  .    .  .
       .. ....  ......
      ..  .   ...     .
     .. .... ..  .   ...
```

Or you can specify the number of cells per generation (`-n`),
the number of generations (`-g`),
the rule number (`-r`),
the character that will be used as 1 (`-t`) and 0 (`f`). Example:

```bash
$ ./ca -h
Usage [-r rule] [-t on] [-f off] [-n n_cells] [-g n_gens]
$ ./ca -t '#' -g 15
```

Result:

```bash
----------------------------
Rule:                    030
Binary rule:        00011110
Number of gens:          015
Number of cells:         028
----------------------------

              #
             ###
            ##  #
           ## ####
          ##  #   #
         ## #### ###
        ##  #    #  #
       ## ####  ######
      ##  #   ###     #
     ## #### ##  #   ###
    ##  #    # #### ##  #
   ## ####  ## #    # ####
  ##  #   ###  ##  ## #   #
 ## #### ##  ### ###  ## ###
 #  #    # ###   #  ###  #
```
