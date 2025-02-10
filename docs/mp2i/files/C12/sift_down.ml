  let extract_min theap =
    let minv = theap.data.(0) in
    theap.data.(0) <- theap.data.(theap.size-1);
    let cp = ref 0 in
    let lc = ref (leftchild !cp theap.size) in
    while ( !lc <> (-1) && (theap.data.(!lc) < theap.data.(!cp) || (!lc+1 < theap.size && theap.data.(!lc+1) < theap.data.(!cp)))) do
      if (!lc+1 >= theap.size || theap.data.(!lc)<theap.data.(!lc+1)) then
       (swap theap.data !cp !lc;
        cp := !lc)
      else  
        (swap theap.data !cp (!lc+1);
        cp := !lc+1);
      lc := leftchild !cp theap.size;
    done;
    theap.size <- theap.size -1;
    minv;;
