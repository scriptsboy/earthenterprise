// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <alloca.h>

#include <notify.h>
#include <gstTable.h>

gstTable::gstTable(const char* n)
    : gstMemory(n),
      num_rows_(0),
      num_columns_(0),
      header_(gstHeaderImpl::Create()) {
}

gstTable::~gstTable() {
}

void gstTable::SetHeader(const gstHeaderHandle hdr) {
  header_ = hdr;
  num_columns_ = header_->numColumns();
}

gstRecordHandle gstTable::NewRecord() {
  return header_->NewRecord();
}


