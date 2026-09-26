// 00417864 FUN_00417864 [Global]
// programa: sfmain.exe

void __fastcall FUN_00417864(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  undefined8 uVar2;
  
  iVar1 = DAT_0043d564;
  if ((((param_2 == 0) || (DAT_0043d708 == 0)) && (DAT_004623a0 == 0)) &&
     ((in_EAX != DAT_0043d560 || (param_2 != DAT_0043d564)))) {
    DAT_0043d564 = param_2;
    uVar2 = FUN_0041848a(param_1,param_2);
    DAT_00462398 = (undefined4)uVar2;
    if (in_EAX == 0) {
      if (param_2 == 0) {
        DAT_0043d604 = 1;
      }
      else {
        DAT_0043d604 = 3;
      }
    }
    else {
      DAT_0043d604 = 2;
    }
    DAT_004623a0 = 1;
    DAT_0046238c = in_EAX;
    DAT_00462390 = param_2;
  }
  DAT_0043d564 = iVar1;
  return;
}


