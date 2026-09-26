// 004136fc FUN_004136fc [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004136fc(void)

{
  int in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar2;
  
  iVar1 = (DAT_004627ac * 1000) / DAT_0043d69c;
  DAT_0043d32c = 0;
  if (DAT_0043d558 != 0x91) {
    FUN_0042bd59();
    FUN_0042b8c2(extraout_ECX,extraout_EDX);
    fVar2 = FUN_0042b8ce();
    if ((in_EAX < (int)ROUND(fVar2)) && (DAT_0043d714 < (DAT_00459ddd * iVar1) / 1000)) {
      if (DAT_00459de1 < 1) {
        DAT_004393d8 = 0;
        DAT_0043d32c = 1;
        return;
      }
      DAT_00459de1 = DAT_00459de1 - DAT_004393d8;
    }
    else if (DAT_0043d558 < 0x8f) {
      if (DAT_0043d558 == 0x8e) {
        DAT_00459de1 = 8000;
      }
    }
    else if (DAT_0043d558 < 0x90) {
      DAT_00459de1 = 16000;
    }
    else if (DAT_0043d558 == 0x90) {
      DAT_00459de1 = 24000;
    }
  }
  DAT_00459ddd = DAT_00459ddd + 1;
  return;
}


