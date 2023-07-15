---
icon: fontawesome/solid/house-chimney
---


# Welcome to MkDocs

For full documentation visit [mkdocs.org](https://www.mkdocs.org).

Un peu de $x^2$

!!! note Un test
    Juste pour voir

Un code 

``` yaml
theme:
  features:
    - content.code.annotate # (1)
```

1.  :man_raising_hand: I'm a code annotation! I can contain `code`, __formatted
    text__, images, ... basically anything that can be written in Markdown.


``` ocaml
let fact n =
    if n=0 then 1 else n * fact(n-1) (*(1)*)

let toto = 20
```

1.  Petit test

Une petite icone :material-test-tube:

## Commands

* `mkdocs new [dir-name]` - Create a new project.
* `mkdocs serve` - Start the live-reloading docs server.
* `mkdocs build` - Build the documentation site.
* `mkdocs -h` - Print help message and exit.

## Project layout

    mkdocs.yml    # The configuration file.
    docs/
        index.md  # The documentation homepage.
        ...       # Other markdown pages, images and other files.

=== "C"

    ``` c
    #include <stdio.h>

    int main(void) {
      printf("Hello world!\n");
      return 0;
    }
    ```

=== "C++"

    ``` c++
    #include <iostream>

    int main(void) {
      std::cout << "Hello world!" << std::endl;
      return 0;
    }
    ```
