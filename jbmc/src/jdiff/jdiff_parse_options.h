/*******************************************************************\

Module: JDIFF Command Line Option Processing

Author: Peter Schrammel

\*******************************************************************/

/// \file
/// JDIFF Command Line Option Processing

#ifndef CPROVER_JDIFF_JDIFF_PARSE_OPTIONS_H
#define CPROVER_JDIFF_JDIFF_PARSE_OPTIONS_H

#include <analyses/goto_check.h>

#include <util/options.h>
#include <util/parse_options.h>
#include <util/timestamper.h>
#include <util/ui_message.h>

#include <goto-programs/goto_model.h>
#include <goto-programs/show_goto_functions.h>
#include <goto-programs/show_properties.h>

class goto_modelt;

// clang-format off
#define JDIFF_OPTIONS \
  "(json-ui)" \
  OPT_SHOW_GOTO_FUNCTIONS \
  OPT_SHOW_PROPERTIES \
  OPT_GOTO_CHECK \
  "(cover):" \
  "(verbosity):(version)" \
  "(no-lazy-methods)" /* should go away */ \
  "(no-refine-strings)" /* should go away */ \
  OPT_TIMESTAMP \
  "u(unified)(change-impact)(forward-impact)(backward-impact)" \
  "(compact-output)"
// clang-format on

class jdiff_parse_optionst : public parse_options_baset, public messaget
{
public:
  virtual int doit();
  virtual void help();

  jdiff_parse_optionst(int argc, const char **argv);

protected:
  ui_message_handlert ui_message_handler;
  void register_languages();

  void get_command_line_options(optionst &options);

  bool process_goto_program(const optionst &options, goto_modelt &goto_model);
};

#endif // CPROVER_JDIFF_JDIFF_PARSE_OPTIONS_H
