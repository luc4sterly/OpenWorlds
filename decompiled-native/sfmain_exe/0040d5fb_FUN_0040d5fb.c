// 0040d5fb FUN_0040d5fb [Global]
// program: sfmain.exe

void __fastcall FUN_0040d5fb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined8 uVar3;
  int iVar4;
  char *local_34;
  CHAR local_30 [24];
  
  if (DAT_0043d640 != (HWND)0x0) {
    if (DAT_00445b24 < 0) {
      if (DAT_004393b8 < 2) {
        if (DAT_004393b8 == 1) {
          uVar3 = FUN_00429192(param_1,param_2);
          local_34 = (char *)uVar3;
          uVar2 = extraout_ECX;
        }
        else {
          uVar3 = FUN_00429192(param_1,param_2);
          local_34 = (char *)uVar3;
          uVar2 = extraout_ECX_00;
        }
        FUN_0042c5c6(uVar2,local_34);
      }
      else {
        iVar4 = DAT_004393b8;
        uVar3 = FUN_00429192(param_1,param_2);
        wsprintfA(local_30,(LPCSTR)uVar3,iVar4);
      }
    }
    else {
      iVar1 = DAT_00445b24 + 1;
      iVar4 = DAT_004393b8;
      uVar3 = FUN_00429192(param_1,param_2);
      wsprintfA(local_30,(LPCSTR)uVar3,iVar1,iVar4);
    }
    SetDlgItemTextA(DAT_0043d640,0x40b,local_30);
  }
  return;
}


