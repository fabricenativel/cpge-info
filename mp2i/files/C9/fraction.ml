type fraction = {mutable numerateur : int; mutable denominateur : int}

let a = {numerateur=45; denominateur=12}

let rec pgcd a b =
  if b = 0 then a else pgcd b (a mod b)

let simplifie f =
  let d = pgcd f.numerateur f.denominateur in
  f.numerateur <- f.numerateur/d;
  f.denominateur <- f.denominateur/d;;

let affiche f =
  Printf.printf "%d/%d\n" f.numerateur f.denominateur

let () = affiche a; simplifie a; affiche a;