// 0043fff0 FUN_0043fff0 [Global]
// programa: gamma.dll

void __thiscall FUN_0043fff0(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int *piStack_14;
  
  bVar1 = true;
  if ((*(int *)(param_1 + 8) != 1) && (*(int *)(param_1 + 8) != 2)) {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                      (*(undefined4 **)(param_1 + 0xc),&DAT_00467198,&piStack_14);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*piStack_14 + 0x1c))(piStack_14);
      (**(code **)(*piStack_14 + 8))(piStack_14);
      if (-1 < iVar2) {
        *(undefined4 *)(param_1 + 8) = 3;
        *(undefined4 *)(param_1 + 4) = param_2;
        return;
      }
    }
    FUN_0044d5a0(s_Can_t_play__0047806c);
  }
  return;
}


