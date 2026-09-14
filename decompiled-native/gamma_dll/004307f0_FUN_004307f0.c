// 004307f0 FUN_004307f0 [Global]
// programa: gamma.dll

void __thiscall FUN_004307f0(void *this,int *param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_3 != (char *)0x0) {
    FUN_004356e0();
    FUN_0044d6b0((char *)((int)this + 0xc00),param_3);
    iVar1 = FUN_00403fc0(param_1,param_3);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x2e0))(param_1,iVar1,0);
      iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar1);
      FUN_004304e0(this,param_1,param_2,puVar2,iVar3);
      (**(code **)(*param_1 + 0x300))(param_1,iVar1,puVar2,0);
    }
  }
  return;
}


