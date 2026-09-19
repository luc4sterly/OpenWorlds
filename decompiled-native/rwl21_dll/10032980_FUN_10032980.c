// 10032980 FUN_10032980 [Global]
// programa: RWL21.DLL

uint FUN_10032980(uint param_1)

{
  if (*(int *)(param_1 + 0xa0) == 0) {
    if ((*(uint *)(param_1 + 0x188) & 4) != 0) {
      return 2;
    }
    param_1 = (*(uint *)(param_1 + 0x188) & 2) >> 1;
  }
  return param_1;
}


