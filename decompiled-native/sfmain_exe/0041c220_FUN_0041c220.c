// 0041c220 FUN_0041c220 [Global]
// program: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x0041c9a3) */
/* WARNING: Removing unreachable block (ram,0x0041c9c4) */
/* WARNING: Removing unreachable block (ram,0x0041c9af) */
/* WARNING: Removing unreachable block (ram,0x0041c975) */
/* WARNING: Removing unreachable block (ram,0x0041c95e) */
/* WARNING: Removing unreachable block (ram,0x0041c98c) */
/* WARNING: Removing unreachable block (ram,0x0041c9e4) */

int __fastcall FUN_0041c220(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar3;
  undefined4 extraout_ECX_01;
  undefined4 uVar4;
  int extraout_EDX;
  char *pcVar5;
  undefined8 uVar6;
  char local_5c;
  int local_58;
  char *local_54;
  int local_34;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = 0;
  if (param_2 == 0) {
    FUN_0041c1ec(param_1,0);
  }
  else {
    uVar2 = FUN_0042cc60(param_1,(uint *)&DAT_00436610);
    if (uVar2 == 0) {
      return 0;
    }
    FUN_0042a55e(extraout_ECX,&local_24);
    local_34 = 0;
    uVar4 = extraout_ECX_00;
    iVar3 = extraout_EDX;
    while ((local_34 < local_24 && (local_1c != 1))) {
      if ((**(char **)(local_34 * 4 + local_20) == '-') ||
         (**(char **)(local_34 * 4 + local_20) == '/')) {
        local_58 = 0;
        local_54 = (char *)(*(int *)(local_34 * 4 + local_20) + 2);
        while (((&DAT_00437bd8)[(byte)(*local_54 + 1)] & 0x20) != 0) {
          iVar3 = local_58 * 10;
          local_58 = *local_54 + iVar3 + -0x30;
          local_54 = local_54 + 1;
        }
        uVar2 = (int)*(char *)(*(int *)(local_34 * 4 + local_20) + 1) - 0x32;
        if (uVar2 < 0x47) {
          local_5c = (char)uVar2;
          iVar3 = 0x1e;
          pcVar5 = "FEDCBA@?>=<;987654310/&$\x12\x06\x04\x01";
          goto code_r0x0041c3f8;
        }
        uVar6 = FUN_0041c1ec(uVar4,iVar3);
        iVar3 = (int)((ulonglong)uVar6 >> 0x20);
        local_1c = 1;
        uVar4 = extraout_ECX_01;
      }
      local_34 = local_34 + 1;
    }
  }
  return local_1c;
  while( true ) {
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    if (local_5c == cVar1) break;
code_r0x0041c3f8:
    if (iVar3 == 0) break;
  }
                    /* WARNING: Could not recover jumptable at 0x0041c3fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)(&PTR_LAB_0041c360)[iVar3])();
  return iVar3;
}


