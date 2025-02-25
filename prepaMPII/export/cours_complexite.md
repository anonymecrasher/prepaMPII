  # analison le code suivant

```c
int slow_add(int a, int b) {
	assert (a >= 0 && b >= 0);
	int i = 0;
	while (a > 0) {
		i = i + 1; a = a - 1;
	}
	while (b > 0) {
		i = i + 1; b = b - 1;
	}
	return i;
}
```

### reperons les invariant
```c
int slow_add(int a, int b) {
	assert (a >= 0 && b >= 0);
	int i = 0;
	while (a > 0) {//a+i = a0
		i = i + 1; a = a - 1;
	}
	while (b > 0) {//b+i = b0 + a0
		i = i + 1; b = b - 1;
	}
	return i;//=a0 + b0
}
```

add : 1 addition = O(1)
slowadd : 2(a+b) addition = O(a+b)

Un = O(Vn) ssi il existe n0 appartenant a N, k appartenant a R+
quelquesoit n >= n0 , un <= k . Vn


mult : 2a additions = O(a)
slowmult: <= a(1+2(ab + b)) additions car i <= ab donc slowmult(i,b) fait moi,s de 2(ab + b) addition

### programme de mult
```c
int mult(int a, int b) {
  assert (a >= 0);
  int i = 0;
  while (a > 0) {
    a = a - 1; i = i + b;
  }
  return i;
}
```

### programme de fastmult
```c
int fast_mult(int a, int b) {
  assert (a >= 0);
  int i = 0;
  while (a > 0) {
    if (a % 2 == 1) {
      i = i + b;
    }
    a = a / 2; b = 2 * b;
  }
  return i;
}
```

#### étude de la complexite des 2 programme
mult : 2 a addition = O(a)
fastmult : <= ⌊log2(a)⌋ * 3 opération = O(log2(a))
