// 0042b59b FUN_0042b59b [Global]
// programa: sfmain.exe

void __fastcall FUN_0042b59b(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_EAX;
  int unaff_EBX;
  float10 fVar2;
  int local_14;
  
  FUN_0042b0fb();
  if (30000 < unaff_EBX) {
    FUN_004296b9(s_Forced_to_reduce_sig_len_from__d_004377de);
    unaff_EBX = 30000;
  }
  if (DAT_0043d5e0 != 0) {
    for (local_14 = 0; local_14 < unaff_EBX; local_14 = local_14 + 1) {
      *(float *)(local_14 * 4 + 0x4c78c4) = (float)*(short *)(local_14 * 2 + param_2);
    }
    FUN_0042b3b8(*in_EAX,(int)(in_EAX + 0xf3),0x4c78c4,unaff_EBX,(int)(in_EAX + 0x11b),
                 (int)(in_EAX + 0x12f),(float)in_EAX[2]);
    for (local_14 = 0; local_14 < unaff_EBX; local_14 = local_14 + 1) {
      fVar2 = FUN_0042b8ce();
      iVar1 = (int)ROUND(fVar2);
      if (iVar1 < -0x8000) {
        *(undefined2 *)(local_14 * 2 + param_2) = 0x8000;
      }
      else if (iVar1 < 0x8000) {
        *(short *)(local_14 * 2 + param_2) = (short)iVar1;
      }
      else {
        *(undefined2 *)(local_14 * 2 + param_2) = 0x7fff;
      }
    }
  }
  return;
}


