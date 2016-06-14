#
# Copyright (c) 2015-2016 Wind River Systems, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

APP_DIR := ${PROJECT_ROOT}/application

# Get the settings for the application, libraries, & kernel
PROJECT_MAKE_SETTINGS := $(shell find . -name sdkApp.mk) \
	$(shell find . -name sdkLibrary.mk) \
	$(shell find . -name sdkKernel.mk)

-include ${HAC_SDK_DIR}/resources/sdkEnv.mk

include $(PROJECT_MAKE_SETTINGS)

clean:
	@make pristine

