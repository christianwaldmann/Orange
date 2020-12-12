# Contributing to Orange!

Thanks for your interest in contributing to Orange! :tada: I love getting [pull requests](https://www.quora.com/GitHub-What-is-a-pull-request) for bugfixes and contributions of the community to keep Orange growing.

I want to keep it as easy as possible to contribute changes. These guidelines are intended to help smooth that process, and allow me to review and approve your changes quickly and easily. Improvements are always welcome! Feel free to [open an issue][issue-tracker] or [submit a new pull request][submit-pr]. And finally, these are just guidelines, not rules, so use your best judgement when necessary.

If you're new to [GitHub][github], you may want to begin with [Getting Started with GitHub](https://help.github.com/en/categories/getting-started-with-github) and Thinkful's [GitHub Pull Request Tutorial](https://www.thinkful.com/learn/github-pull-request-tutorial/).

## Language

The code base, issues and pull requests should be in English only.
Thanks for your understanding.

## Reporting Bugs

Bugs should be reported on our [GitHub Issue Tracker][issue-tracker] using the bug report template.

Follow the advice in [How do I ask a good question?][how-to-ask]. While the article is intended for people asking questions on Stack Overflow, it all applies to writing a good bug report too.

## Requesting New Features

Feature requests should also be sent to our [GitHub Issue Tracker][issue-tracker] using the feature request template.

-   Explain the problem that you're having, and anything you've tried to solve it using the currently available features.

-   Explain how this new feature will help.

-   If possible, provide an example, like a code snippet, showing what your new feature might look like in use.

Also, much of the advice in [How do I ask a good question?][how-to-ask] applies here too.

## Contributing a Fix or Feature

You've created a new fix or feature for Orange. Awesome!

1. If you haven't already, create a fork of the Orange repository.

2. Create a topic branch, and make all of your changes on that branch.

3. Submit a pull request, use the implemented issue template if it is based on an issue or the new issue template if it is not linked to any issue.

4. Give me a moment. Orange is maintained by only myself, so it may take me a bit to review your request.

If you're not sure what any of that means, check out Thinkful's [GitHub Pull Request Tutorial](https://www.thinkful.com/learn/github-pull-request-tutorial/) for a complete walkthrough of the process.

### Writing a Good Pull Request

-   Stay focused on a single fix or feature. If you submit multiple changes in a single request, I may like some but spot issues with others. When that happens, I have to reject the whole thing. If you submit each change in its own request it is easier for me to review and approve.

-   Limit your changes to only what is required to implement the fix or feature. In particular, avoid style or formatting tools that may modify the formatting of other areas of the code.

-   Follow our coding conventions, which I've intentionally kept quite minimal.

### Coding Conventions

-   For variables I use readable camel case: `doSomethingCool`. If they are class members use the 'm*' prefix: `m_DoSomethingCool`. When they are static use the 's*' prefix: `s_DoSomethingCool`.

-   Use tabs for indentation, not spaces.

-   When in doubt, match the code that's already there.

[github]: https://github.com
[how-to-ask]: https://stackoverflow.com/help/how-to-ask
[issue-tracker]: https://github.com/christianwaldmann/Orange/issues
[submit-pr]: https://github.com/christianwaldmann/Orange/pulls
