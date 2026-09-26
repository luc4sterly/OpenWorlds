// 004102eb FUN_004102eb [Global]
// programa: sfmain.exe

void __fastcall FUN_004102eb(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined8 uVar1;
  char *local_28;
  char *local_24;
  char *local_20;
  
  if (*(int *)(param_2 + 0x4f78) == 0) {
    InvalidateRect(in_EAX,(RECT *)0x0,0);
    UpdateWindow(in_EAX);
  }
  else {
    if (((*(int *)(param_2 + 0x4e58) == 0) || (**(char **)(param_2 + 0x4e58) == '\0')) ||
       (**(char **)(param_2 + 0x4e58) == -1)) {
      if (*(short *)(param_2 + 0x4e42) == 0) {
        if (*(int *)(param_2 + 0x640) == 0) {
          local_20 = (char *)(param_2 + 0x2c);
        }
        else {
          uVar1 = FUN_00429192(param_1,param_2);
          local_20 = (char *)uVar1;
          param_1 = extraout_ECX_00;
        }
        local_24 = local_20;
      }
      else {
        uVar1 = FUN_00429192(param_1,param_2);
        local_24 = (char *)uVar1;
        param_1 = extraout_ECX;
      }
      local_28 = local_24;
    }
    else {
      local_28 = *(char **)(param_2 + 0x4e58);
    }
    if (*(int *)(param_2 + 0x654) == 0) {
      SetWindowTextA(in_EAX,local_28);
    }
    else {
      FUN_0042c5c6(param_1,&DAT_00435d22);
      FUN_0042caa9(extraout_ECX_01,local_28);
      SetWindowTextA(in_EAX,&DAT_00459941);
    }
  }
  return;
}


