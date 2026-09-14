// 00413550 FUN_00413550 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00413550(undefined4 param_1)

{
  float fVar1;
  bool bVar2;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  FUN_004193f0(param_1,&local_1c,&local_10);
  bVar2 = false;
  fVar1 = (((((local_10 - local_1c) + local_c) - local_14) + local_8) - local_14) * _DAT_0046f720;
  local_1c = local_1c + fVar1;
  local_10 = local_10 - fVar1;
  local_18 = local_18 + fVar1;
  local_c = local_c - fVar1;
  local_14 = local_14 + fVar1;
  local_8 = local_8 - fVar1;
  if (local_1c <= local_10) {
    if (local_18 <= local_c) {
      if (local_14 <= local_8) goto LAB_004135e9;
    }
  }
  bVar2 = true;
LAB_004135e9:
  if ((local_10 < local_1c) || (!bVar2)) {
    local_1c = local_1c - (fVar1 + fVar1);
    local_10 = local_10 + fVar1 + fVar1;
  }
  if ((local_c < local_18) || (!bVar2)) {
    local_18 = local_18 - (fVar1 + fVar1);
    local_c = local_c + fVar1 + fVar1;
  }
  if ((local_8 < local_14) || (!bVar2)) {
    local_14 = local_14 - (fVar1 + fVar1);
    local_8 = local_8 + fVar1 + fVar1;
  }
  FUN_00413210(&local_1c,&local_10,DAT_0046f724,DAT_0046f724,DAT_0046f724);
  return;
}


