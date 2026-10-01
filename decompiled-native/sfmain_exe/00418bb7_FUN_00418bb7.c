// 00418bb7 FUN_00418bb7 [Global]
// program: sfmain.exe

void __fastcall FUN_00418bb7(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  int local_1c;
  
  if (DAT_0043d520 != 0) {
    DAT_0043d684 = 1;
    FUN_00417715(param_1,param_2);
    for (local_1c = 0; param_1 = extraout_ECX, local_1c < 8; local_1c = local_1c + 1) {
      *(undefined4 *)(&DAT_0045a200 + local_1c * 4) = 0;
    }
  }
  FUN_0042b0bf(param_1,0x386);
  return;
}


