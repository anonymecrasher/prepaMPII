let (^+) c str = (String.make 1 c) ^ str
let rec prochain_argument cdc flag = 
  if not(flag) && not(cdc.[0] = ' ') then "" 
  else 
    if cdc.[0] = ' ' && not(flag)
    then prochain_argument (String.sub cdc 1 ((String.length cdc)-1)) false
    else
      cdc.[0] ^+ (prochain_argument (String.sub cdc 1 ((String.length cdc)-1)) (not(cdc.[0] = ' ')))
let a = prochain_argument "hkuleshgfsyqga a a a a a a a a a a a a a a a a b" false



