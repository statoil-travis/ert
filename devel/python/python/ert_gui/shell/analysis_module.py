from ert_gui.shell import ShellFunction, assertConfigLoaded, extractFullArgument, autoCompleteListWithSeparator, matchItems


class AnalysisModule(ShellFunction):
    def __init__(self, shell_context):
        super(AnalysisModule, self).__init__("analysis_module", shell_context)

        self.addHelpFunction("current", None, "Shows the current analysis module.")
        self.addHelpFunction("list", None, "Shows a list of the available analysis modules.")
        self.addHelpFunction("options", None, "Shows a list of the available options for the current analysis module.")
        self.addHelpFunction("select", "<analysis_module>", "Select an analysis module.")
        self.addHelpFunction("set", "<variable_name> <value>", "Set a variable value.")


    @assertConfigLoaded
    def do_current(self, args):
        analysis_module = self.ert().analysisConfig().activeModuleName()
        print("Analysis Module set to: %s" % analysis_module)

    @assertConfigLoaded
    def do_list(self, args):
        items = self.getAnalysisModules()
        self.columnize(items)

    def getAnalysisModules(self):
        analysis_modules = self.ert().analysisConfig().getModuleList()
        items = [analysis_module for analysis_module in analysis_modules]
        return items

    @assertConfigLoaded
    def do_select(self, line):
        keys = matchItems(line, self.getAnalysisModules())

        if len(keys) == 0 or len(keys) > 1:
            self.lastCommandFailed("Must enter a single valid Analysis Module")

        analysis_module_name = list(keys)[0]
        self.ert().analysisConfig().selectModule(analysis_module_name)

    @assertConfigLoaded
    def complete_select(self, text, line, begidx, endidx):
        key = extractFullArgument(line, endidx)
        return autoCompleteListWithSeparator(key, self.getAnalysisModules())

    @assertConfigLoaded
    def do_variables(self, args):
        active_module = self.ert().analysisConfig().getActiveModule()
        variables = active_module.getVariableNames()

        format = " %-20s %-6s %-20s %s"
        print(format % ("Name", "Type", "Value", "Description"))

        for variable_name in variables:
            variable_type = active_module.getVariableType(variable_name).__name__
            variable_value = active_module.getVariableValue(variable_name)
            variable_description = active_module.getVariableDescription(variable_name)
            print(format % (variable_name, variable_type, variable_value, variable_description))


    @assertConfigLoaded
    def do_set(self, line):
        arguments = self.splitArguments(line)

        if len(arguments) > 1:
            active_module = self.ert().analysisConfig().getActiveModule()
            variables = active_module.getVariableNames()
            variable, argument = line.split(" ", 1)

            if not variable in variables:
                self.lastCommandFailed("Variable with name: %s, not available in analysis module!" % variable)
            else:
                variable_type = active_module.getVariableType(variable)
                try:
                    value = variable_type(argument)
                    active_module.setVar(variable, argument)
                except ValueError:
                    self.lastCommandFailed("Unable to convert '%s' into to a: %s" % (argument, variable_type.__name__))

        else:
            self.lastCommandFailed("This keyword requires a variable name and a value.")



    @assertConfigLoaded
    def complete_set(self, text, line, begidx, endidx):
        arguments = self.splitArguments(line)

        if len(arguments) > 2 or len(arguments) == 2 and not text:
            return []

        active_module = self.ert().analysisConfig().getActiveModule()
        variables = active_module.getVariableNames()
        return autoCompleteListWithSeparator(text, variables)