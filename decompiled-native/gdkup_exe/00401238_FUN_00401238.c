// 00401238 FUN_00401238 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_00401238(undefined4 param_1,uint param_2)

{
  undefined4 in_EAX;
  undefined4 uStack_1c;
  
  if ((param_2 & 4) == 0) {
    uStack_1c = FUN_004012d4(param_1,1);
    if ((param_2 & 2) != 0) {
      FUN_004026bc();
    }
  }
  else {
    FUN_00402694();
    thunk_FUN_004026bc();
    uStack_1c = in_EAX;
  }
  return uStack_1c;
}


