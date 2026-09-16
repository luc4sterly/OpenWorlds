// 00440070 FUN_00440070 [Global]
// programa: gamma.dll

void __fastcall FUN_00440070(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piStack_14;
  
  bVar1 = true;
  if ((*(int *)(param_1 + 8) != 3) && (*(int *)(param_1 + 8) != 1)) {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                      (*(undefined4 **)(param_1 + 0xc),&DAT_00467198,&piStack_14);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*piStack_14 + 0x20))(piStack_14);
      (**(code **)(*piStack_14 + 8))(piStack_14);
      if (-1 < iVar2) {
        *(undefined4 *)(param_1 + 8) = 2;
        return;
      }
    }
    FUN_0044d5a0(s_Can_t_pause_0047807c);
  }
  return;
}


