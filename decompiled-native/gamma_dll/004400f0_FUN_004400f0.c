// 004400f0 FUN_004400f0 [Global]
// program: gamma.dll

void __fastcall FUN_004400f0(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piStack_14;
  int *piStack_10;
  
  bVar1 = true;
  if ((*(int *)(param_1 + 8) != 3) && (*(int *)(param_1 + 8) != 2)) {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                      (*(undefined4 **)(param_1 + 0xc),&DAT_00467198,&piStack_14);
    if (-1 < iVar2) {
      (**(code **)(*piStack_14 + 0x20))(piStack_14);
      iVar2 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                        (*(undefined4 **)(param_1 + 0xc),&DAT_00467178,&piStack_10);
      if (-1 < iVar2) {
        (**(code **)(*piStack_10 + 0x20))(piStack_10,DAT_00478090,DAT_00478094);
        (**(code **)(*piStack_10 + 8))(piStack_10);
      }
      (**(code **)(*piStack_14 + 0x3c))(piStack_14);
      (**(code **)(*piStack_14 + 8))(piStack_14);
      *(undefined4 *)(param_1 + 8) = 1;
      return;
    }
    FUN_0044d5a0(s_Can_t_stop_00478098);
  }
  return;
}


