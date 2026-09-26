// 004012d4 FUN_004012d4 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_004012d4(undefined4 param_1,uint param_2)

{
  undefined4 in_EAX;
  
  if ((param_2 & 4) == 0) {
    if ((param_2 & 2) != 0) {
      FUN_004026bc();
    }
  }
  else {
    FUN_00402694();
    thunk_FUN_004026bc();
  }
  return in_EAX;
}


