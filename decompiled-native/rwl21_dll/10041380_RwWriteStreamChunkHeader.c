// 10041380 RwWriteStreamChunkHeader [Global]
// program: RWL21.DLL

void RwWriteStreamChunkHeader(int *param_1,uint param_2,uint param_3)

{
  uint local_8;
  uint local_4;
  
                    /* 0x41380  529  RwWriteStreamChunkHeader */
  local_8 = (param_2 & 0xff0000 | param_2 >> 0x10) >> 8 | (param_2 & 0xff00 | param_2 << 0x10) << 8;
  local_4 = (param_3 & 0xff0000 | param_3 >> 0x10) >> 8 | (param_3 & 0xff00 | param_3 << 0x10) << 8;
  RwWriteStream(param_1,&local_8,8);
  return;
}


