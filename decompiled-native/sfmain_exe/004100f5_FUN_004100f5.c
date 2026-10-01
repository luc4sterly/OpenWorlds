// 004100f5 FUN_004100f5 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004100f5(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_EDX;
  undefined8 uVar1;
  
  if (*(int *)(param_2 + 0x640) == 0) {
    uVar1 = FUN_00429192(param_1,param_2);
    Ordinal_111((int)uVar1);
    uVar1 = FUN_00429482(extraout_ECX_00,extraout_EDX);
    uVar1 = FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar1 >> 0x20),500,
                         s__GAMMA_speakfre_sfmain_CONNECT_c_00435d01,2,in_EAX,0x30,s__s___s_00435cfa
                        );
  }
  else {
    uVar1 = FUN_00429192(param_1,param_2);
    uVar1 = FUN_00429268(extraout_ECX,(int)((ulonglong)uVar1 >> 0x20),0x1f1,
                         s__GAMMA_speakfre_sfmain_CONNECT_c_00435cd9,3,in_EAX,0x30,(LPCSTR)uVar1);
  }
  return uVar1;
}


