
let rec opti lm  deb fin= 
  let n = fin-deb+1 in
  if n=1 then 0 else
  if n=2 then let l1,c1 = lm.(deb) in let l2,c2 = lm.(fin) in l1*c1*c2 else
    (
      let minc = ref Int.max_int in
      for k = deb to fin-1 do 
        let r1 = opti lm deb k in
        let r2 = opti lm (k+1) fin in
        let l1,c1 = lm.(deb) in
        let l2,c2 = lm.(k) in
        let l3,c3 = lm.(fin) in
        if r1+r2+l1*c2*c3 < !minc then minc := r1+r2+l1*c2*c3 
        done;
        !minc;
    );;
  

let construit lv =
  let res = Array.make (Array.length lv -1) (0,0) in
  for i= 0 to (Array.length lv -2) do
    res.(i) <- lv.(i),lv.(i+1)
  done;
  res;;


    let () =
    let tv = [|(5,2);(2,10);(10,4);(4,1)|] in
    let lv = [|27;98;89;40;36;82;6;11;3;23;15;91;87;35;3;43|] in
    let tv2 = construit lv in
    let np = opti tv2 0 (Array.length tv2 -1) in
    Printf.printf "Nombre optimal = %d \n" np;;