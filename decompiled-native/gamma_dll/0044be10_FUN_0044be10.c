// 0044be10 FUN_0044be10 [Global]
// programa: gamma.dll

void __thiscall
FUN_0044be10(void *this,int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_00458020();
  }
  iVar1 = (**(code **)(*param_1 + 0x29c))(param_1,param_2);
  if (iVar1 == 0) {
    FUN_00458020();
  }
  FUN_00430490(param_4);
  FUN_00403f80(param_1,*(undefined4 *)((int)this + 4),*(undefined4 *)((int)this + 8));
  return;
}


