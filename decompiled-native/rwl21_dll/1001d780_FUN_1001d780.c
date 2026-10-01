// 1001d780 FUN_1001d780 [Global]
// program: RWL21.DLL

undefined4 FUN_1001d780(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_1005ac40;
  piVar1 = DAT_1005ac40 + 2;
  if (0 < DAT_1005ac40[2]) {
    *piVar1 = DAT_1005ac40[2] + -1;
  }
  return *(undefined4 *)(*piVar2 + *piVar1 * 4);
}


