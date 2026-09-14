// 00431440 FUN_00431440 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00431440(void *this,undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  undefined *puVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float fVar6;
  undefined **local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined **local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined **local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  undefined **local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined **local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34 [5];
  undefined **local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  
  cVar1 = (*(code *)**(undefined4 **)this)();
  puVar4 = param_1;
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)((int)this + 8);
  }
  local_84 = &PTR_LAB_00473390;
  local_80 = puVar4[1];
  local_7c = puVar4[2];
  local_78 = puVar4[3];
  *(undefined1 *)((int)this + 4) = 1;
  *(undefined4 *)((int)this + 0xc) = param_1[1];
  *(undefined4 *)((int)this + 0x10) = param_1[2];
  *(undefined4 *)((int)this + 0x14) = param_1[3];
  FUN_00428e20((void *)((int)this + 0x18),param_2);
  *(undefined4 *)((int)this + 0x2c) = *param_3;
  *(undefined4 *)((int)this + 0x30) = param_3[1];
  *(undefined4 *)((int)this + 0x34) = *param_4;
  *(undefined4 *)((int)this + 0x38) = param_4[1];
  FUN_00428d70(&local_54,(int)this + 8,(int)&local_84);
  local_70 = local_50;
  local_54 = &PTR_LAB_004732e8;
  local_74 = &PTR_LAB_004732e8;
  local_68 = local_48;
  local_6c = local_4c;
  puVar2 = FUN_0042f9f0();
  fVar5 = FUN_004295e0((int)&local_74,(int)puVar2);
  fVar6 = (float)fVar5;
  puVar2 = FUN_0042f9f0();
  FUN_00429520(&local_44,(int)puVar2,fVar6);
  local_70 = local_70 - local_40;
  local_44 = &PTR_LAB_004732e8;
  local_6c = local_6c - local_3c;
  local_68 = local_68 - local_38;
  fVar5 = FUN_004295e0((int)&local_74,(int)&local_74);
  if (fVar5 < (float10)_DAT_00475068) {
    pvVar3 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar3 + 4) = 0x21;
    fVar6 = _DAT_004823b0;
  }
  else {
    fVar6 = SQRT((float)fVar5);
  }
  *(float *)((int)this + 0x4c) = fVar6;
  *(undefined4 *)((int)this + 0x48) = *(undefined4 *)((int)this + 0x4c);
  FUN_00429170(local_34,param_2);
  FUN_004291c0(local_34,&local_20,(int)&local_74);
  local_60 = local_1c;
  local_64 = &PTR_LAB_004732e8;
  local_20 = &PTR_LAB_004732e8;
  local_5c = local_18;
  local_58 = local_14;
  FUN_00428e50(local_34);
  if (local_5c <= _DAT_00475070) {
    *(undefined4 *)((int)this + 0x3c) = 2;
    *(float *)((int)this + 0x48) = -*(float *)((int)this + 0x48);
  }
  else {
    *(undefined4 *)((int)this + 0x3c) = 1;
  }
  return;
}


