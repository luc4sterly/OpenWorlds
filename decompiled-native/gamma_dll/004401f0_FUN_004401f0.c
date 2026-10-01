// 004401f0 FUN_004401f0 [Global]
// program: gamma.dll

void __fastcall FUN_004401f0(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *local_28;
  int local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  int *local_18;
  int *local_14;
  
  iVar2 = (*(code *)**(undefined4 **)param_1[3])((undefined4 *)param_1[3],&DAT_00467188,&local_28);
  if (iVar2 < 0) {
    return;
  }
  iVar2 = (**(code **)(*local_28 + 0x20))(local_28,&local_24,local_20,local_1c,0);
  if (-1 < iVar2) {
    if (local_24 == 1) {
      (**(code **)(*param_1 + 0x20))();
      if (param_1[1] == -1) {
        (**(code **)(*param_1 + 0x18))(0xffffffff);
      }
      else {
        param_1[1] = param_1[1] + -1;
        if (0 < param_1[1]) {
          (**(code **)(*param_1 + 0x18))(param_1[1]);
        }
      }
    }
    else if (local_24 - 2U < 2) {
      bVar1 = true;
      if ((param_1[2] != 3) && (param_1[2] != 2)) {
        bVar1 = false;
      }
      if (bVar1) {
        iVar2 = (*(code *)**(undefined4 **)param_1[3])
                          ((undefined4 *)param_1[3],&DAT_00467198,&local_14);
        if (-1 < iVar2) {
          (**(code **)(*local_14 + 0x24))(local_14);
          (**(code **)(*local_14 + 8))(local_14);
          iVar2 = (*(code *)**(undefined4 **)param_1[3])
                            ((undefined4 *)param_1[3],&DAT_00467178,&local_18);
          if (-1 < iVar2) {
            (**(code **)(*local_18 + 0x20))(local_18,DAT_00478090,DAT_00478094);
            (**(code **)(*local_18 + 8))(local_18);
            param_1[2] = 1;
            goto LAB_0044030b;
          }
        }
        FUN_0044d5a0(s_Can_t_stop_00478098);
      }
    }
  }
LAB_0044030b:
  (**(code **)(*local_28 + 8))(local_28);
  return;
}


