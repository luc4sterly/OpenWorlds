// 100037e0 FUN_100037e0 [Global]
// program: RWL21.DLL

int * FUN_100037e0(uint param_1,int param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  
  piVar2 = FUN_10001220(param_2,*(int *)(param_1 + 0x88),param_3);
  if (piVar2 != (int *)0x0) {
    bVar1 = FUN_10003660(param_1,piVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      RwDestroyPolygon(piVar2);
      return (int *)0x0;
    }
  }
  return piVar2;
}


