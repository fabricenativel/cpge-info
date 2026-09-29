let division a b =
  try
    a/b
  with
  | Division_by_zero -> Int.max_int