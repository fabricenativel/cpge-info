let est_dans elt tab =
  try
  for i=0 to (Array.length tab -1) do
      if tab.(i)=elt then raise Exit;
  done;
  false
  with
| Exit -> true;;