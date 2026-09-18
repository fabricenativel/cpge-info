open Queue;;

let dernier nb_enfants longueur =
  let cercle = Queue.create () in
  let enfant = ref 0 in
  for i=0 to nb_enfants-1 do
    Queue.add i cercle
  done;
  for i=1 to nb_enfants-1 do
    for j=0 to longueur-1 do
      enfant := Queue.take cercle;
      Queue.push !enfant cercle;
    done;
      ignore (Queue.take cercle);
  done;
  Queue.take cercle;;

