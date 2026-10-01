// 00405ee0 FUN_00405ee0 [Global]
// program: gamma.dll

int FUN_00405ee0(void *param_1,uint param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  ushort uVar3;
  int *piVar4;
  int *this;
  char *pcVar5;
  char cVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char local_7c;
  uint local_78;
  bool local_74;
  uint local_70;
  uint local_64;
  uint *local_5c;
  int local_58 [2];
  int local_50 [2];
  int local_48;
  undefined1 local_42;
  undefined1 local_41;
  
  FUN_004049b0(param_1,local_58);
  local_41 = DAT_004890b4;
  piVar4 = (int *)FUN_00404a00(local_58);
  FUN_00404dc0(local_58);
  if (param_2 == 0) {
    uVar2 = (**(code **)(*piVar4 + 0x14))(0x30);
    *param_3 = uVar2;
    return 1;
  }
  FUN_004049b0(param_1,local_50);
  local_42 = DAT_004890b6;
  this = (int *)FUN_00406190(local_50);
  FUN_00404dc0(local_50);
  local_70 = 10;
  uVar3 = *(ushort *)((int)param_1 + 0x30) & 0x4a;
  if (uVar3 == 8) {
    local_70 = 0x10;
  }
  else if (uVar3 == 0x40) {
    local_70 = 8;
  }
  FUN_004060e0(this,&local_48);
  FUN_00406490(&local_5c,&local_48);
  FUN_00404ed0(&local_48);
  local_78 = 0;
  local_74 = *local_5c != 0;
  local_7c = '\0';
  cVar6 = '\0';
  if (local_74) {
    pcVar5 = (char *)FUN_00406260(&local_5c,0);
    local_7c = *pcVar5;
    if (local_7c == '\0') {
      local_74 = false;
    }
  }
  local_64 = CONCAT22(local_64._2_2_,*(undefined2 *)((int)param_1 + 0x30));
  puVar8 = param_3;
  while (puVar1 = puVar8, param_2 != 0) {
    uVar2 = FUN_00406120(local_64,piVar4,param_2 % local_70);
    *puVar1 = uVar2;
    puVar8 = puVar1 + 1;
    param_2 = param_2 / local_70;
    if (((param_2 != 0) && (local_74)) && (cVar6 = cVar6 + '\x01', cVar6 == local_7c)) {
      uVar2 = FUN_004060d0(this);
      *puVar8 = uVar2;
      local_78 = local_78 + 1;
      if (local_78 < *local_5c) {
        pcVar5 = (char *)FUN_00406260(&local_5c,local_78);
        local_7c = *pcVar5;
        if (local_7c == '\0') {
          local_74 = false;
        }
      }
      cVar6 = '\0';
      puVar8 = puVar1 + 2;
    }
  }
  if ((param_3 != puVar1) && (puVar7 = puVar1 + -1, puVar8 = param_3, param_3 < puVar7)) {
    do {
      uVar2 = *puVar8;
      *puVar8 = *puVar7;
      *puVar7 = uVar2;
      puVar7 = puVar7 + -1;
      puVar8 = puVar8 + 1;
    } while (puVar8 < puVar7);
  }
  FUN_00404ed0((int *)&local_5c);
  return (int)puVar1 - (int)param_3;
}


