// 10041520 RwWriteStreamInt [Global]
// programa: RWL21.DLL

void RwWriteStreamInt(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
                    /* 0x41520  530  RwWriteStreamInt */
  uVar4 = param_3 >> 2;
  puVar2 = param_2;
  for (uVar3 = uVar4; uVar3 != 0; uVar3 = uVar3 - 1) {
    uVar1 = *puVar2;
    *puVar2 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
    puVar2 = puVar2 + 1;
  }
  RwWriteStream(param_1,param_2,param_3);
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar3 = *param_2;
    *param_2 = (uVar3 & 0xff00 | uVar3 << 0x10) << 8 | (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8;
    param_2 = param_2 + 1;
  }
  return;
}


