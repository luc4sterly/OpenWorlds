// 004135f9 FUN_004135f9 [Global]
// programa: sfmain.exe

int __fastcall FUN_004135f9(undefined4 param_1,int param_2)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBX;
  float10 fVar1;
  undefined4 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_24 = 0;
  local_1c = 0;
  for (local_20 = 0; local_20 < param_2; local_20 = local_20 + 1) {
    local_34 = *(int *)((uint)*(byte *)(in_EAX + local_1c) * 2 + 0x426f90) >> 0x10;
    if (local_34 < 0) {
      local_34 = -local_34;
    }
    local_24 = local_24 + local_34;
    local_1c = local_1c + 1;
  }
  if (param_2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 / param_2;
  }
  if (local_24 == 0) {
    local_18 = 0;
  }
  else {
    FUN_0042bd59();
    FUN_0042bd59();
    fVar1 = FUN_0042b8ce();
    local_18 = (int)ROUND(fVar1);
    param_1 = extraout_ECX;
  }
  if (unaff_EBX == 0) {
    FUN_004173ab(param_1,local_18);
  }
  else {
    FUN_00416836();
    FUN_004173ab(extraout_ECX_00,local_18);
  }
  return local_24;
}


