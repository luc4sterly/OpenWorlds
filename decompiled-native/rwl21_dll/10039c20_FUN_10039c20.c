// 10039c20 FUN_10039c20 [Global]
// program: RWL21.DLL

int * FUN_10039c20(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_10037030(DAT_1005b790);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x28);
    *piVar1 = iVar2;
    if (iVar2 != 0) {
      piVar1[2] = 0;
      piVar1[1] = 10;
      return piVar1;
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(0);
      FUN_10037010(DAT_1005b790,piVar1);
    }
  }
  return (int *)0x0;
}


