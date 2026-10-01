// 00404600 _Java_NET_worlds_network_DNSLookup_gethostbyname@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_network_DNSLookup_gethostbyname_12
              (int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int local_88;
  int local_84;
  CHAR local_74 [100];
  
                    /* 0x4600  180  _Java_NET_worlds_network_DNSLookup_gethostbyname@12 */
  uVar2 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar3 = Ordinal_52(uVar2);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar2);
  if (iVar3 != 0) {
    local_84 = 0;
    piVar5 = *(int **)(iVar3 + 0xc);
    while (*piVar5 != 0) {
      local_84 = local_84 + 1;
      piVar5 = piVar5 + 1;
    }
    if (0 < local_84) {
      uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_java_lang_String_0046d5d0);
      iVar4 = (**(code **)(*param_1 + 0x2b0))(param_1,local_84,uVar2,0);
      if (iVar4 == 0) {
        FUN_00402800(s_nDNSLookup_0046d5e4,0x24);
      }
      puVar6 = *(undefined4 **)(iVar3 + 0xc);
      local_88 = 0;
      if (0 < local_84) {
        do {
          uVar1 = *(uint *)*puVar6;
          wsprintfA(local_74,s__d__d__d__d_0046d5f0,uVar1 & 0xff,uVar1 >> 8 & 0xff,
                    uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
          uVar2 = (**(code **)(*param_1 + 0x29c))(param_1,local_74);
          (**(code **)(*param_1 + 0x2b8))(param_1,iVar4,local_88,uVar2);
          local_88 = local_88 + 1;
          puVar6 = puVar6 + 1;
        } while (local_88 < local_84);
      }
      return iVar4;
    }
  }
  return 0;
}


