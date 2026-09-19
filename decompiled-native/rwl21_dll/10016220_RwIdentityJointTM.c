// 10016220 RwIdentityJointTM [Global]
// programa: RWL21.DLL

bool RwIdentityJointTM(void)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x16220  274  RwIdentityJointTM */
  puVar1 = (undefined4 *)FUN_1001d710(DAT_1005dfd0);
  iVar2 = FUN_1001c4a0(puVar1);
  return (bool)('\x01' - (iVar2 == 0));
}


