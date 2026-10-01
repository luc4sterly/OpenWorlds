// 10041410 RwWriteStreamReal [Global]
// program: RWL21.DLL

bool RwWriteStreamReal(int *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
                    /* 0x41410  532  RwWriteStreamReal */
  if ((int)param_3 < 0x400) {
    puVar3 = &DAT_1005e070;
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar4 = param_3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)puVar3 = (char)*param_2;
      param_2 = (uint *)((int)param_2 + 1);
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    puVar3 = &DAT_1005e070;
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      uVar1 = *puVar3;
      *puVar3 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
      puVar3 = puVar3 + 1;
    }
    bVar2 = RwWriteStream(param_1,&DAT_1005e070,param_3);
    return bVar2;
  }
  puVar3 = (uint *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_3);
  if (puVar3 != (uint *)0x0) {
    puVar5 = puVar3;
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar4 = param_3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)puVar5 = (char)*param_2;
      param_2 = (uint *)((int)param_2 + 1);
      puVar5 = (uint *)((int)puVar5 + 1);
    }
    puVar5 = puVar3;
    for (uVar4 = param_3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      uVar1 = *puVar5;
      *puVar5 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
      puVar5 = puVar5 + 1;
    }
    bVar2 = RwWriteStream(param_1,puVar3,param_3);
    (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar3);
    return bVar2;
  }
  return false;
}


