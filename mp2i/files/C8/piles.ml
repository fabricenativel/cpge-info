let est_vide p = p==[]

let empile p n = n::p

let depile p = match p with
| [] -> failwith "La pile est vide"
| h::t -> h, t