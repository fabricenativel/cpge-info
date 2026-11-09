let a = ref 42;;
let b = ref 2023;;
let temp = ref !a;;
a := !b;
b := !temp;
