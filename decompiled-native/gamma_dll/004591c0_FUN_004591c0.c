// 004591c0 FUN_004591c0 [Global]
// program: gamma.dll

undefined4 FUN_004591c0(int param_1,char *param_2,DWORD *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_00454f40((undefined4 *)&DAT_004824bc);
  uVar1 = FUN_0044dad0(param_1,param_2,*param_3);
  *param_3 = uVar1;
  if (*param_3 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


